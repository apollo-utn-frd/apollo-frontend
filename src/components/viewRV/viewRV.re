let component = ReasonReact.statelessComponent("ViewRV");

[@bs.module "./view-rv"]
external reactClass : ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
