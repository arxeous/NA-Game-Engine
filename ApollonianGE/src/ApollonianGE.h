#pragma once

// For use by AGE applications
// Applications will need to inherit from the app.h and app.cpp files for application class
// So we dont have to write ApollonianGE/Application.h each time, we make one ApollonianGE.h file with all our necessary includes
// We then tell premake to add the directory this file is conatainted in into its include path

#include "ApollonianGE/Application.h"
#include "ApollonianGE/Log.h"

// --Entry Point----------
#include "ApollonianGE/EntryPoint.h"
// -----------------------