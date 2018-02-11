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

let subscription = component => {
  open ReasonReact;
  Js.log(component.state);
  Sub(
    () =>
      switch (A.getCurrentAction(component.state)) {
      | R.ShowAuthPage(authInfo) =>
        component.send(A.AuthAction(Auth.UpdateAuthInfo(authInfo)))
      | _ => component.send(A.AuthAction(Auth.DoNothing))
      },
    () => {
      Js.log("Cerrada subscription");
      component.send(A.AuthAction(Auth.ResetAuthInfo));
    }
  );
};