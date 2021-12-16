#pragma once

// For use by AGE applications
// Applications will need to inherit from the app.h and app.cpp files the application class
// So we dont have to write ApollonianGE/Application.h each time, we make one ApollonianGE.h file with all our necessary includes
// We then tell VSstudio to add the directory this file is conatainted in into its include path

#include "ApollonianGE/application.h"
#include <stdio.h>

// --Entry Point----------
#include "ApollonianGE/EntryPoint.h"
// -----------------------