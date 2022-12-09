import React from "react";

const Slide = props => {
  const { index, level, current } = props;

  let classNames = "slide";
  if (current === index) classNames += " slide--current";
  else if (current - 1 === index) classNames += " slide--previous";
  else if (current + 1 === index) classNames += " slide--next";

  return (
    <li className={classNames}>
      <h3 className="slide__content">{level}</h3>
    </li>
  );
};

export default Slide;
