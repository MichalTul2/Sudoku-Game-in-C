import React, { useState, useEffect, useRef } from "react";
import Tile from "../../components/Tile/Tile";
import NumberButtons from "../../components/NumberButtons/NumberButtons";
import ModeButtons from "../../components/ModeButtons.js/ModeButtons";

const GameView = props => {
  const [board, setBoard] = useState([]);
  const [numberPick, setNumberPick] = useState(null);
  const [currentMode, setCurrentMode] = useState(null);

  useEffect(() => {
    fetch(
      `https://sugoku.herokuapp.com/board?difficulty=${props.match.params.level.toLowerCase()}`
    )
      .then(response => response.json())
      .then(post => {
        return setBoard(post.board);
      });
  }, []);

  const handleNumberPick = value => {
    setNumberPick(value);
  };
  const handleModePick = mode => {
    setCurrentMode(mode);
  };
  const handleTilePick = (rowIndex, columnIndex) => {
    console.log(rowIndex, columnIndex);
  };
  return (
    <div className="game">
      <div className="game__board">
        {board.map((row, rowIndex) => {
          return row.map((value, columnIndex) => {
            return (
              <Tile
                value={value}
                rowIndex={rowIndex}
                columnIndex={columnIndex}
                onClick={handleTilePick}
              />
            );
          });
        })}
      </div>
      <div className="game__inputs">
        <NumberButtons onClick={handleNumberPick} />
      </div>
      <div className="game__mode">
        <ModeButtons onClick={handleModePick} />
      </div>
      <h3>Number pick: {numberPick}</h3>
      <h3>Current Mode: {currentMode}</h3>
    </div>
  );
};

export default GameView;
