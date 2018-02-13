open Utils;

module AuthT = Types.Auth;

type state = AuthT.state;

type action =
  | UpdateInfo(AuthT.t)
  | ResetInfo;

let component = ReasonReact.reducerComponent("Auth");

let make = (~credentials: option(authInfo), _children) => {
  ...component,
  initialState: () => Types.Auth.NoAuthInfo,
  reducer: (action: action, state: state) =>
    switch action {
    | ResetInfo => ReasonReact.Update(state)
    | UpdateInfo(a) =>
      ReasonReact.Update(
        {
          AuthT.saveToLocalStorage(a);
          ReasonReact.Router.push("/");
          state;
        }
      )
    },
  didMount: _self =>
    switch credentials {
    | None => ReasonReact.NoUpdate
    | Some(cs) =>
      ReasonReact.UpdateWithSideEffects(
        AuthT.AuthInfo(cs),
        (
          self => {
            self.send(UpdateInfo(cs));
            ReasonReact.Router.push("/");
          }
        )
      )
    },
  render: _self => <div> <h3> (Utils.str("Redirigiendo")) </h3> </div>
};
