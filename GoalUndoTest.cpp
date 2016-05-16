/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoslUndoTest, AddFirstGoal)
{
    GoalUndo Goaladd;
    Goaladd.addOperation("Fitness", "Running");
    ASSERT_EQ("Fitness", Goaladd.getGoal() );
}

TEST(GoslUndoTest, AddEmptyGoal)
{
    GoalUndo GoalEmpty;
    GoalEmpty.addOperation("", "Walking");
    ASSERT_EQ("", GoalEmpty.getGoal() );
}

TEST(GoslUndoTest, AddEmptyOperation)
{
    GoalUndo OperationEmpty;
    OperationEmpty.addOperation("Fitness", "");
    OperationEmpty.addOperation("");
    ASSERT_EQ("", OperationEmpty.getGoal() );
}

TEST(GoslUndoTest, AddGoals)
{
    GoalUndo addGoals;
    addGoals.addOperation("Fitness", "Running");
    addGoals.addOperation("Good Grades", "Study");
    addGoals.addOperation("","Running");
    ASSERT_EQ("Good Grades", addGoals.getGoal() );
}

TEST(GoslUndoTest, AddOperations)
{
    GoalUndo addOperations;
    addOperations.addOperation("Fitness", "Running");
    addOperations.addOperation("Walking");
    addOperations.addOperation("Gym");
    ASSERT_EQ("Running Walking Gym", addOperations.getOperations() );
}

TEST(GoslUndoTest, GetEmptyOperation)
{
    GoalUndo emptyOperation;
    emptyOperation.addOperation("Fitness", "Running");
    emptyOperation.undoOperation();
    ASSERT_EQ("", emptyOperation.getOperations() );
    ASSERT_EQ("", emptyOperation.getGoal() );
}

TEST(GoslUndoTest, GetOperations)
{
    GoalUndo getOperation;
    getOperation.addOperation("Fitness", "Running");
    getOperation.undoOperation();
    getOperation.addOperation("Study", "Timetable");
    getOperation.addOperation("Wake up early in the Morning");
    ASSERT_EQ("Timetable Wake up early in the Morning", getOperation.getOperations() );
}

TEST(GoslUndoTest, RemoveGoal)
{
    GoalUndo Goaldelete;
    Goaldelete.addOperation("Fitness", "Running");
    Goaldelete.addOperation("Study", "Timetable");
    Goaldelete.addOperation("Hard Work");
    Goaldelete.undoGoal();
    ASSERT_EQ("Fitness", Goaldelete.getGoal() );
}

TEST(GoslUndoTest, RemoveEmptyGoal)
{
    GoalUndo Goaldelete;
    Goaldelete.addOperation("Fitness", "Running");
    Goaldelete.undoGoal();
    ASSERT_EQ("", Goaldelete.getGoal() );
}
