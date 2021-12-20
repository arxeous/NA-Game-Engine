#pragma once
#include "agezpch.h"
#include "ApollonianGE/Core.h"

namespace ApollonianGE {
	// Events for now will be blocking events. I.e. much like in OS once we get an event 
	// We handle it immedeatly and go back once it has been handled. Also like in OS 
	// The better alternative is to put these in a buffer/PQ 

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};



	// This is really just a paramterized macro more than using define for functions
	// The #type will expand type into a string so we can use it to return our actual type. If we just put EventType::type the preprocessor would not expand type correctly
	// ## is used for concatenation for things that arent strings. 

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
							   virtual EventType GetEventType() const override {return GetStaticType(); }\
							   virtual const char* GetName() const override {return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category; }

	// const = 0  makes our functions 1. pure virtual functions because of that = 0 and 2. makes specfies that the fucntion should not change the data within the class.
	class AGEZ_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;

	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_Event(event) {
		}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}
