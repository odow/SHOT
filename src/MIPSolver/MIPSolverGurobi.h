/**
   The Supporting Hyperplane Optimization Toolkit (SHOT).

   @author Andreas Lundell, Åbo Akademi University

   @section LICENSE 
   This software is licensed under the Eclipse Public License 2.0. 
   Please see the README and LICENSE files for more information.
*/

#pragma once
#include "../Enums.h"
#include "IMIPSolver.h"
#include "gurobi_c++.h"
#include "MIPSolverBase.h"

class MIPSolverGurobi : public IMIPSolver, public MIPSolverBase
{
  public:
    MIPSolverGurobi();
    MIPSolverGurobi(EnvironmentPtr envPtr);
    virtual ~MIPSolverGurobi();

    virtual void checkParameters();

    virtual bool createLinearProblem(OptProblem *origProblem);
    virtual void initializeSolverSettings();
    virtual void writeProblemToFile(std::string filename);
    virtual void writePresolvedToFile(std::string filename);

    virtual int addLinearConstraint(std::vector<IndexValuePair> elements, double constant)
    {
        return (addLinearConstraint(elements, constant, false));
    }
    virtual int addLinearConstraint(std::vector<IndexValuePair> elements, double constant, bool isGreaterThan);

    virtual void createHyperplane(Hyperplane hyperplane)
    {
        MIPSolverBase::createHyperplane(hyperplane);
    }

    virtual void createIntegerCut(std::vector<int> binaryIndexes)
    {
        MIPSolverBase::createIntegerCut(binaryIndexes);
    }

    virtual void createInteriorHyperplane(Hyperplane hyperplane)
    {
        MIPSolverBase::createInteriorHyperplane(hyperplane);
    }

    virtual boost::optional<std::pair<std::vector<IndexValuePair>, double>> createHyperplaneTerms(
        Hyperplane hyperplane)
    {
        return (MIPSolverBase::createHyperplaneTerms(hyperplane));
    }

    virtual void fixVariable(int varIndex, double value);

    virtual void fixVariables(std::vector<int> variableIndexes, std::vector<double> variableValues)
    {
        MIPSolverBase::fixVariables(variableIndexes, variableValues);
    }

    virtual void unfixVariables()
    {
        MIPSolverBase::unfixVariables();
    }

    virtual void updateVariableBound(int varIndex, double lowerBound, double upperBound);
    virtual std::pair<double, double> getCurrentVariableBounds(int varIndex);

    virtual void presolveAndUpdateBounds()
    {
        return (MIPSolverBase::presolveAndUpdateBounds());
    }

    virtual std::pair<std::vector<double>, std::vector<double>> presolveAndGetNewBounds();

    virtual void activateDiscreteVariables(bool activate);
    virtual bool getDiscreteVariableStatus()
    {
        return (MIPSolverBase::getDiscreteVariableStatus());
    }

    virtual E_ProblemSolutionStatus solveProblem();
    virtual E_ProblemSolutionStatus getSolutionStatus();
    virtual int getNumberOfSolutions();
    virtual std::vector<double> getVariableSolution(int solIdx);
    virtual std::vector<SolutionPoint> getAllVariableSolutions()
    {
        return (MIPSolverBase::getAllVariableSolutions());
    }
    virtual double getDualObjectiveValue();
    virtual double getObjectiveValue(int solIdx);
    virtual double getObjectiveValue()
    {
        return (MIPSolverBase::getObjectiveValue());
    }

    virtual int increaseSolutionLimit(int increment);
    virtual void setSolutionLimit(long limit);
    virtual int getSolutionLimit();

    virtual void setTimeLimit(double seconds);

    virtual void setCutOff(double cutOff);

    virtual void addMIPStart(std::vector<double> point);
    virtual void deleteMIPStarts();

    virtual bool supportsQuadraticObjective();
    virtual bool supportsQuadraticConstraints();

    virtual std::vector<GeneratedHyperplane> *getGeneratedHyperplanes()
    {
        return (MIPSolverBase::getGeneratedHyperplanes());
    }

    virtual void updateNonlinearObjectiveFromPrimalDualBounds()
    {
        return (MIPSolverBase::updateNonlinearObjectiveFromPrimalDualBounds());
    }

    virtual int getNumberOfExploredNodes();

    virtual int getNumberOfOpenNodes()
    {
        return (MIPSolverBase::getNumberOfOpenNodes());
    }

    GRBEnv *gurobiEnv;
    GRBModel *gurobiModel;

  private:
};

class GurobiInfoCallback : public GRBCallback
{
  public:
    GurobiInfoCallback(EnvironmentPtr envPtr);

  protected:
    void callback();

  private:
    int numVar = 0;
    int lastExploredNodes = 0;
    int lastOpenNodes = 0;
    EnvironmentPtr env;
};
