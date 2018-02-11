module R = Types.Router;

module A = Types.App;

module Auth = Types.Auth;

let updateState = (state: A.state, component, action) => {
  Js.log("Actualizada a " ++ R.string_of_action(action));
  ReasonReact.Update({
    ...state, /* leave user state unchanged and only modify the router state */
    routerState: R.updateRouterState(component, action)
  });
};

let reduce = (action: R.action, state: A.state) =>
  switch action {
  | ShowWelcome => updateState(state, <Welcome />, ShowWelcome)
  | ShowHome => updateState(state, <Home />, ShowHome)
  | ShowSignUp(creds) =>
    updateState(state, <SignUp credentials=creds />, ShowSignUp(creds))
  | ShowAuthPage(creds) =>
    /* Aca recibo la respuesta con la info de auth del usuario, tengo que sacar los campos
       y enviarlos a App.re para actualice el estado */
    let sendAuthInfo = u => {
      let get = (dict, field) =>
        Js.Dict.get(dict, field) |> Utils.Option.unwrapUnsafely;
      ();
    };
    let comp = <AuthPage credentials=(Some(creds)) onReceive=sendAuthInfo />;
    updateState(state, comp, ShowAuthPage(creds));
  };

let subscription = component =>
  ReasonReact.(
    Sub(
      () =>
        Router.watchUrl(url =>
          switch url.path {
          | ["home"] => component.send(A.RouterAction(ShowHome))
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