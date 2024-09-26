#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/undo_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"
#include "./mock_command.h"

TEST(UndoCommandTest, undoShouldBeCorrect)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory commandHistory;
    UndoCommand undoCommand(&mockDragAndDrop, &commandHistory);
    MockCommand *mock1 = new MockCommand();
    MockCommand *mock2 = new MockCommand();
    MockCommand *mock3 = new MockCommand();
    MockCommand *mock4 = new MockCommand();

    commandHistory.addCommand(mock1);
    commandHistory.addCommand(mock2);
    commandHistory.addCommand(mock3);
    commandHistory.addCommand(mock4);
    undoCommand.execute();
    undoCommand.execute();

    ASSERT_TRUE(mock4->isUndoCalled());
    ASSERT_TRUE(mock3->isUndoCalled());
    ASSERT_FALSE(mock2->isUndoCalled());
    ASSERT_FALSE(mock1->isUndoCalled());
}