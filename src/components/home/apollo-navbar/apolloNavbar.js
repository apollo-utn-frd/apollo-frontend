import React from "react";
import "./apolloNavbar.css";
import {
  Collapse,
  Navbar,
  NavbarToggler,
  NavbarBrand,
  Nav,
  NavItem,
  NavLink
} from "reactstrap";

export default class Nav extends React.Component {
/*   constructor(props) {
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
  } */
  render() {
    return (
      <div>
      <h1>hola</h1>{/* 
        <Navbar className="navbar" dark expand="md" fixed="top">
          <div className="contenido">
            <NavbarBrand href="/">APOLLO</NavbarBrand>
            <NavbarToggler onClick={this.toggle} />
            <Collapse isOpen={this.state.isOpen} navbar>
                <Nav className="ml-auto" navbar>
                <NavItem>
                    <NavLink href="#about">Acerca de</NavLink>
                </NavItem>
                <NavItem>
                    <NavLink href="#team">Nosotros</NavLink>
                </NavItem>
                <NavItem>
                    <NavLink href="#contact">Contacto</NavLink>
                </NavItem>
                </Nav>
            </Collapse>
          </div>
        </Navbar> */}
      </div>
    );
  }
}
