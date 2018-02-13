module R = Types.Router;

module A = Types.App;

module Auth = Types.Auth;

let updateState = (state: A.state, component, action) =>
  ReasonReact.Update({
    ...state, /* leave user state unchanged and only modify the router state */
    routerState: R.updateRouterState(component, action)
  });

let reduce = (action: R.action, state: A.state) =>
  switch action {
  | ShowWelcome => updateState(state, <Welcome />, ShowWelcome)
  | ShowHome => updateState(state, <Home />, ShowHome)
  | ShowViewRV => updateState(state, <ViewRV />, ShowViewRV)
  | ShowSignUp(creds) =>
    updateState(state, <SignUp credentials=creds />, ShowSignUp(creds))
  | ShowAuthPage(creds) =>
    /* update the auth state with the credentials */
    updateState(
      {...state, authState: Auth.AuthInfo(creds)},
      <AuthPage credentials=(Some(creds)) />,
      ShowAuthPage(creds)
    )
  };

let subscription = component =>
  ReasonReact.(
    Sub(
      () =>
        Router.watchUrl(url =>
          switch url.path {
          | ["home"] => component.send(A.RouterAction(ShowHome))
          | ["viewrv"] => component.send(A.RouterAction(ShowViewRV))
          | ["signup"] =>
            switch (component.state |> A.getUserAuthInfo) {
            | NoAuthInfo => component.send(A.RouterAction(ShowWelcome))
            | AuthInfo(a) => component.send(A.RouterAction(ShowSignUp(a)))
            }
          | ["auth"] =>
            switch (Utils.extractQuerystring(url.search)) {
            | None => component.send(A.RouterAction(ShowWelcome))
            | Some(a) => component.send(A.RouterAction(ShowAuthPage(a)))
            }
          | _ => component.send(A.RouterAction(ShowWelcome))
          }
        ),
      Router.unwatchUrl
    )
  );
