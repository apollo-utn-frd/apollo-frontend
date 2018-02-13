open Utils;

requireCSS("bootstrap/dist/css/bootstrap.css");

module RouterT = Types.Router;

module AuthT = Types.Auth;

module AppT = Types.App;

module UserT = Types.User;

type state = AppT.state;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => AppT.initialState,
  didUpdate: ({newSelf, _}) =>
    switch (AppT.getUserAuthInfo(newSelf.state)) {
    | AuthT.NoAuthInfo => ()
    | AuthT.AuthInfo(auth) =>
      Js.log("Estas Logueado");
      /* Aca deberia conseguir el usuario y ver el status de confirmacion
         para decidir a donde enviarlo */
      AppT.getCurrentAction(newSelf.state) == ShowWelcome ?
        newSelf.send(AppT.RouterAction(ShowSignUp(auth))) : ();
    },
  didMount: self => {
    let authInfo = Dom.Storage.localStorage |> AuthT.getFromLocalStorage;
    switch authInfo {
    | None => ReasonReact.NoUpdate
    | Some(authInfo) =>
      ReasonReact.UpdateWithSideEffects(
        self.state,
        (self => self.send(AppT.AuthAction(UpdateAuthInfo(authInfo))))
      )
    };
    /* Obtener usuario? guardar usuario y manejar la logica de mandarlo a home o a signup */
  },
  reducer: (action: AppT.action, state: state) =>
    switch action {
    | RouterAction(action) => Reducer.Router.reduce(action, state)
    | UserAction(action) => Reducer.User.reduce(action, state)
    | AuthAction(action) => Reducer.Auth.reduce(action, state)
    },
  subscriptions: self => [Reducer.Router.subscription(self)],
  render: self => AppT.getCurrentPage(self.state)
};
