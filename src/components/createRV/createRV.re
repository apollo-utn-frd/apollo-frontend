let component = ReasonReact.statelessComponent("CreateRV");

[@bs.module "./create-rv"]
external reactClass : ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);