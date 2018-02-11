open Utils;

type state = Types.Auth.t;

let component = ReasonReact.statelessComponent("Auth");

let make = (~credentials: option(authInfo), ~onReceive: 'a => unit, _children) => {
  ...component,
  /*   reducer: Reducer.Auth.reducer, */
  render: _self => <div> <h3> (Utils.str("Redirigiendo")) </h3> </div>
};
/*     switch credentials {
       | None => Utils.str("No auth information received")
       | Some(cs) =>
         Api.Users.getCurrentUser(cs)
         |> Js.Promise.(then_(u => onReceive(u) |> resolve))
         |> ignore;
         <div> <h3> (Utils.str("Redirigiendo")) </h3> </div>;
       } */
/* <p> (Utils.str("Auth Token: " ++ cs.auth_token)) </p>
   <p> (Utils.str("Client ID: " ++ cs.client_id)) </p>
   <p> (Utils.str("UID: " ++ cs.uid)) </p> */