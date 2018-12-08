/**
   The Supporting Hyperplane Optimization Toolkit (SHOT).

   @author Andreas Lundell, Åbo Akademi University

   @section LICENSE 
   This software is licensed under the Eclipse Public License 2.0. 
   Please see the README and LICENSE files for more information.
*/

#pragma once
#include "Shared.h"

namespace SHOT
{

class Environment
{
  public:
    inline Environment() {};
    inline ~Environment() {};

    ProcessPtr process;
    SettingsPtr settings;
    ModelPtr model;
    ProblemPtr problem;
    ProblemPtr reformulatedProblem;
    ModelingSystemPtr modelingSystem;
    MIPSolverPtr dualSolver;
    OutputPtr output;
    ReportPtr report;
    TaskHandlerPtr tasks;

    SolutionStatistics solutionStatistics;

  private:
};

typedef std::shared_ptr<Environment> EnvironmentPtr;
} // namespace SHOT

#include "TaskHandler.h"