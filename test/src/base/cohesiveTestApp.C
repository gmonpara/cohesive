//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "cohesiveTestApp.h"
#include "cohesiveApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
cohesiveTestApp::validParams()
{
  InputParameters params = cohesiveApp::validParams();
  return params;
}

cohesiveTestApp::cohesiveTestApp(InputParameters parameters) : MooseApp(parameters)
{
  cohesiveTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

cohesiveTestApp::~cohesiveTestApp() {}

void
cohesiveTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  cohesiveApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"cohesiveTestApp"});
    Registry::registerActionsTo(af, {"cohesiveTestApp"});
  }
}

void
cohesiveTestApp::registerApps()
{
  registerApp(cohesiveApp);
  registerApp(cohesiveTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
cohesiveTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cohesiveTestApp::registerAll(f, af, s);
}
extern "C" void
cohesiveTestApp__registerApps()
{
  cohesiveTestApp::registerApps();
}
