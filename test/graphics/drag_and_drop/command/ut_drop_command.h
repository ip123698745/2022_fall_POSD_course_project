#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(DropCommandTest, executeShouldCallDropMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    dropCommand.execute();

    ASSERT_NEAR(85.23, mockDragAndDrop.getDropX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getDropY(), 0.001);
}

TEST(DropCommandTest, undoShouldCallGrabMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    dropCommand.execute();
    dropCommand.undo();

    ASSERT_NEAR(85.23, mockDragAndDrop.getGrabX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getGrabY(), 0.001);
}

TEST(DropCommandTest, getXShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    dropCommand.execute();

    ASSERT_NEAR(85.23, dropCommand.getX(), 0.001);
}

TEST(DropCommandTest, getYShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    dropCommand.execute();

    ASSERT_NEAR(232.7, dropCommand.getY(), 0.001);
}