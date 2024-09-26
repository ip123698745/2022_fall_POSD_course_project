#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/macro_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"
#include "./mock_command.h"

TEST(MacroCommandTest, mockDragAndDropShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MacroCommand macroCommand;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    macroCommand.addCommand(new GrabCommand(&mockDragAndDrop, &history));
    macroCommand.addCommand(new MoveCommand(&mockDragAndDrop, &history));
    macroCommand.addCommand(new DropCommand(&mockDragAndDrop, &history));
    macroCommand.execute();

    ASSERT_NEAR(85.23, mockDragAndDrop.getGrabX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getGrabY(), 0.001);
    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
    ASSERT_NEAR(85.23, mockDragAndDrop.getDropX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getDropY(), 0.001);
}

TEST(MacroCommandTest, getCommandsShouldBeCorrectAfterExecute)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MacroCommand macroCommand;

    MousePosition::getInstance()->setPos(85.23, 232.7);
    macroCommand.addCommand(new GrabCommand(&mockDragAndDrop, &history));
    macroCommand.addCommand(new MoveCommand(&mockDragAndDrop, &history));
    macroCommand.addCommand(new DropCommand(&mockDragAndDrop, &history));

    std::vector<Command *> commands = macroCommand.getCommands();

    ASSERT_TRUE(dynamic_cast<GrabCommand *>(commands.at(0)) != nullptr);
    ASSERT_TRUE(dynamic_cast<MoveCommand *>(commands.at(1)) != nullptr);
    ASSERT_TRUE(dynamic_cast<DropCommand *>(commands.at(2)) != nullptr);
}

TEST(MacroCommandTest, undoShouldBeCorrect)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MacroCommand macroCommand;
    MockCommand *mock1 = new MockCommand();
    MockCommand *mock2 = new MockCommand();
    MockCommand *mock3 = new MockCommand();

    macroCommand.addCommand(mock1);
    macroCommand.addCommand(mock2);
    macroCommand.addCommand(mock3);
    macroCommand.undo();

    ASSERT_TRUE(mock1->isUndoCalled());
    ASSERT_TRUE(mock2->isUndoCalled());
    ASSERT_TRUE(mock3->isUndoCalled());
}