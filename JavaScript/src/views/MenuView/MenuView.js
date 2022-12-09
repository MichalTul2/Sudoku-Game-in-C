import React, { useState } from "react";
import { Link } from "react-router-dom";
import Slide from "../../components/SliderItem/SliderItem";
import SliderControl from "../../components/SliderControl/SliderControl";

const MenuView = () => {
  const [current, setCurrent] = useState(1);
  const levels = ["Easy", "Medium", "Hard", "Random"];

  const handlePreviousClick = () => {
    current > 0 ? setCurrent(current - 1) : setCurrent(current);
  };
  const handleNextClick = () => {
    current < levels.length - 1 ? setCurrent(current + 1) : setCurrent(current);
  };
  return (
    <div className="menu">
      <div className="menu__logo"> </div>

      <div className="menu__slider">
        <SliderControl
          type="previous"
          title="Easier"
          onClick={handlePreviousClick}
        />
        <ul className="slider__wrapper">
          {levels.map((level, index) => {
            return (
              <Slide
                key={level}
                index={index}
                level={level}
                current={current}
              />
            );
          })}
        </ul>
        <SliderControl type="next" title="Harder" onClick={handleNextClick} />
      </div>
      <Link
        to={`/difficulty=${levels[current]}`}
        className="menu__button"
      
        current={current}
      >
        New Game
      </Link>
    </div>
  );
};

export default MenuView;
