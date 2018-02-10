import React from "react";
import "./apolloNavbar.css";
import UserDropdown from "./user-dropdown/user-dropdown";
import {
  Collapse,
  Navbar,
  NavbarToggler,
  NavbarBrand,
  Nav,
  NavItem,
  NavLink,
  InputGroup, 
  InputGroupAddon, 
  Input
} from "reactstrap";

export default class ApolloNav extends React.Component {
    constructor(props) {
    super(props);

    this.toggle = this.toggle.bind(this);
    this.state = {
      isOpen: false
    };
  }
  toggle() {
    this.setState({
      isOpen: !this.state.isOpen
    });
  }
  render() {
    return (
      <div>
        <Navbar className="navbar" dark expand="md" fixed="top">
          <div className="contenido">
            <NavbarBrand href="/">APOLLO</NavbarBrand>
            <NavbarToggler onClick={this.toggle} />
            <Collapse isOpen={this.state.isOpen} navbar></Collapse>
          </div>
          <div clasName="navbar-form navbar-left hidden-sm hidden-xs">
            <InputGroup>
              <InputGroupAddon addonType="prepend">Buscar</InputGroupAddon>
              <Input placeholder="buscando...." />
            </InputGroup>
          </div>
          <div className="collapse navbar-collapse navbar-right navbar-main-collapse">
            <UserDropdown />
          </div>
        </Navbar>
      </div>
    );
  }
}
