import React from "react";

const NumberButtons = ({ onClick }) => {
  const options = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "X"];

  return (
    <>
      {options.map((element, index) => (
        <button key={index} onClick={() => onClick(element)}>
          {element}
        </button>
      ))}
    </>
  );
};

export default NumberButtons;
