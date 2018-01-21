let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self => <h1> (Utils.str("Home Component")) </h1>
};