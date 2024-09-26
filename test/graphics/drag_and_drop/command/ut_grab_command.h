#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(GrabCommandTest, executeShouldCallGrabMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();

    ASSERT_NEAR(85.23, mockDragAndDrop.getGrabX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getGrabY(), 0.001);
}

TEST(GrabCommandTest, undoShouldCallMoveAndDropMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();
    grabCommand.undo();

    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
    ASSERT_NEAR(85.23, mockDragAndDrop.getDropX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getDropY(), 0.001);
}

TEST(GrabCommandTest, getXShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();

    ASSERT_NEAR(85.23, grabCommand.getX(), 0.001);
}

TEST(GrabCommandTest, getYShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();

    ASSERT_NEAR(232.7, grabCommand.getY(), 0.001);
}