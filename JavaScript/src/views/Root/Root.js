import React from "react";
import ReactDOM from "react-dom";
import { BrowserRouter, Route, Switch } from "react-router-dom";
import MenuView from "../MenuView/MenuView";
import GameView from "../GameView/GameView";
import "./style.scss";

const App = () => {
  return (
    <BrowserRouter>
      <>
        <Switch>
          <Route exact path="/" component={MenuView} />
          <Route path="/difficulty=:level" component={GameView} />
        </Switch>
      </>
    </BrowserRouter>
  );
};

ReactDOM.render(<App />, document.getElementById("root"));
