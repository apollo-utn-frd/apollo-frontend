module Auth = Types.Auth;

module R = Types.Router;

module A = Types.App;

let reduce = (action: Auth.action, state: A.state) =>
  switch action {
  | Auth.UpdateAuthInfo(authInfo) =>
    ReasonReact.Update({...state, authState: Auth.AuthInfo(authInfo)})
  | Auth.ResetAuthInfo =>
    ReasonReact.Update({...state, authState: Auth.NoAuthInfo})
  | Auth.DoNothing => ReasonReact.NoUpdate
  };