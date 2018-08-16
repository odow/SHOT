/**
   The Supporting Hyperplane Optimization Toolkit (SHOT).

   @author Andreas Lundell, Åbo Akademi University

   @section LICENSE 
   This software is licensed under the Eclipse Public License 2.0. 
   Please see the README and LICENSE files for more information.
*/

#pragma once
#include "OSInstance.h"
#include "vector"
#include "../OptProblems/OptProblemOriginal.h"

class INLPSolver
{
  public:
    INLPSolver(EnvironmentPtr envPtr);
    virtual ~INLPSolver();

    OptProblem *NLPProblem;
    EnvironmentPtr env;

    virtual void setProblem(OSInstance *origInstance) = 0;
    virtual void initializeProblem() = 0;
    virtual void setStartingPoint(std::vector<int> variableIndexes, DoubleVector variableValues) = 0;
    virtual void clearStartingPoint() = 0;

    virtual E_NLPSolutionStatus solveProblem() = 0;
    virtual void fixVariables(std::vector<int> variableIndexes, DoubleVector variableValues) = 0;

    virtual void unfixVariables() = 0;

    virtual void saveProblemToFile(std::string fileName) = 0;
    virtual void saveOptionsToFile(std::string fileName) = 0;

    virtual DoubleVector getSolution() = 0;
    virtual double getSolution(int i) = 0;
    virtual double getObjectiveValue() = 0;

    virtual bool isObjectiveFunctionNonlinear() = 0;
    virtual int getObjectiveFunctionVariableIndex() = 0;

    virtual DoubleVector getVariableLowerBounds() = 0;
    virtual DoubleVector getVariableUpperBounds() = 0;

  protected:
    virtual E_NLPSolutionStatus solveProblemInstance() = 0;
    virtual bool createProblemInstance(OSInstance *origInstance) = 0;

    virtual DoubleVector getCurrentVariableLowerBounds() = 0;
    virtual DoubleVector getCurrentVariableUpperBounds() = 0;
};
