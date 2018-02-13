let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <div>
        <ApolloNavbar />
        <div className="mt-4 row">
            <ProfileCard />
            <div className="col-md-8 offset-md-1">
                <PreviewRV />
                <PreviewRV />
                <PreviewRV />
            </div>
        </div>
    </div>
    };