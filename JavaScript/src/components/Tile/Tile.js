import React, { useState } from "react";

const Tile = ({ value, rowIndex, columnIndex, option, onClick }) => {
  let divClassNames = "tile";
  if (rowIndex === 2 || rowIndex === 5) divClassNames += " borderDown";
  if (columnIndex === 2 || columnIndex === 5) divClassNames += " borderRight";

  return (
    <div className={divClassNames} key={rowIndex + columnIndex}>
      <p
        className="tile"
        data-rowindex={rowIndex}
        data-columnindex={columnIndex}
        onClick={() => onClick(rowIndex, columnIndex)}
      >
        {value !== 0 ? value : " "}
      </p>
    </div>
  );
};

export default Tile;
