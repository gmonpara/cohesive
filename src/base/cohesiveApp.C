#include "cohesiveApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
cohesiveApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

cohesiveApp::cohesiveApp(InputParameters parameters) : MooseApp(parameters)
{
  cohesiveApp::registerAll(_factory, _action_factory, _syntax);
}

cohesiveApp::~cohesiveApp() {}

void
cohesiveApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"cohesiveApp"});
  Registry::registerActionsTo(af, {"cohesiveApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
cohesiveApp::registerApps()
{
  registerApp(cohesiveApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
cohesiveApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cohesiveApp::registerAll(f, af, s);
}
extern "C" void
cohesiveApp__registerApps()
{
  cohesiveApp::registerApps();
}
