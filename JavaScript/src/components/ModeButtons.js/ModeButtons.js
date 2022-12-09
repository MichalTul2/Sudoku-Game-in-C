import React from "react";
import ResetIcon from "./icons/reset.svg";
import CheckMarkIcon from "./icons/checkmark.svg";
import PencilIcon from "./icons/pencil.svg";
import UndoIcon from "./icons/undo.svg";

const ModeButtons = ({ onClick }) => {
  return (
    <>
      <div className="modeButtons">
        <ResetIcon width={20} height={20} onClick={() => onClick("reset")} />
        <CheckMarkIcon
          width={20}
          height={20}
          onClick={() => onClick("checkmark")}
        />
        <PencilIcon width={20} height={20} onClick={() => onClick("pencil")} />
        <UndoIcon width={20} height={20} onClick={() => onClick("undo")} />
      </div>
    </>
  );
};

export default ModeButtons;
