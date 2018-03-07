/**
   The Supporting Hyperplane Optimization Toolkit (SHOT).

   @author Andreas Lundell, Åbo Akademi University

   @section LICENSE 
   This software is licensed under the Eclipse Public License 2.0. 
   Please see the README and LICENSE files for more information.
*/

#pragma once
#include "TaskBase.h"
#include "../ProcessInfo.h"
#include "../UtilityFunctions.h"
#include "../MIPSolver/IMIPSolver.h"

#ifdef HAS_CPLEX
#include "../MIPSolver/MIPSolverCplex.h"
#include "../MIPSolver/MIPSolverCplexLazy.h"
#include "../MIPSolver/MIPSolverCplexLazyOriginalCallback.h"
#endif

#ifdef HAS_GUROBI
#include "../MIPSolver/MIPSolverGurobi.h"
#include "../MIPSolver/MIPSolverGurobiLazy.h"
#endif

#include "../MIPSolver/MIPSolverOsiCbc.h"

class TaskInitializeDualSolver : public TaskBase
{
  public:
	TaskInitializeDualSolver(ES_MIPSolver solver, bool useLazyStrategy);
	virtual ~TaskInitializeDualSolver();

	void run();
	virtual std::string getType();

  private:
};
