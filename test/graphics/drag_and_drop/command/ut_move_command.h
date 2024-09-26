#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(MoveCommandTest, executeShouldCallMoveMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    moveCommand.execute();

    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
}

TEST(MoveCommandTest, undoShouldCallMoveMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    moveCommand.execute();
    moveCommand.undo();

    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
}

TEST(MoveCommandTest, getXShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    moveCommand.execute();

    ASSERT_NEAR(85.23, moveCommand.getX(), 0.001);
}

TEST(MoveCommandTest, getYShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    moveCommand.execute();

    ASSERT_NEAR(232.7, moveCommand.getY(), 0.001);
}