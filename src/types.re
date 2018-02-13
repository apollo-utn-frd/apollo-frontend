module Auth = {
  type t = Utils.authInfo;
  type action =
    | UpdateAuthInfo(t)
    | DoNothing
    | ResetAuthInfo;
  type state =
    | AuthInfo(t)
    | NoAuthInfo;
};

module User = {
  type action =
    | UpdateUser
    | NoUser;
  type state =
    | Nothing;
};

module Router = {
  type state = {
    currentPage: ReasonReact.reactElement,
    url: string,
    currentAction: action
  }
  and action =
    | ShowWelcome
    | ShowHome
    | ShowSignUp(Utils.authInfo)
    | ShowAuthPage(Utils.authInfo)
    | ShowViewRV;
  let string_of_action = action =>
    switch action {
    | ShowWelcome => "/"
    | ShowHome => "home"
    | ShowSignUp(_) => "signup"
    | ShowAuthPage(_) => "auth"
    | ShowViewRV => "viewrv"
    };
  let updateRouterState = (component, action) => {
    currentPage: component,
    url: string_of_action(action),
    currentAction: action
  };
};

module App = {
  type action =
    | RouterAction(Router.action)
    | UserAction(User.action)
    | AuthAction(Auth.action);
  type state = {
    userState: User.state,
    routerState: Router.state,
    authState: Auth.state
  };
  let initialState = {
    userState: User.Nothing,
    routerState: {
      currentPage: <Welcome />,
      url: Router.string_of_action(Router.ShowWelcome),
      currentAction: ShowWelcome
    },
    authState: Auth.NoAuthInfo
  };
  let getCurrentPage = state => state.routerState.currentPage;
  let getUrl = state => state.routerState.url;
  let getCurrentUser = state => state.userState;
  let getCurrentAction = state => state.routerState.currentAction;
  let getUserAuthInfo = state => state.authState;
};