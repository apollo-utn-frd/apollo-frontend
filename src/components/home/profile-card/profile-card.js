import React from "react";
import {
  Card,
  CardBody,
  Button,
  CardTitle,
  CardText,
  CardImg,
  CardSubtitle,
  ListGroup,
  ListGroupItem
} from "reactstrap";

export default class UserCard extends React.Component {
  render() {
    return (
      <div className="col-md-2 p-2">
        <Card className="user">
          <CardImg
            width="100%"
            src="https://lh4.googleusercontent.com/-WHb2PGFg70g/AAAAAAAAAAI/AAAAAAAAAAA/4KM01AzHqeo/photo.jpg"
            alt="Card image cap"
          />

          <section className="seguir center-x">
            <button className="btn btn-danger">
              <i class="fa fa-user-times" aria-hidden="true" />Eliminar
            </button>
            <button className="btn btn-primary">
              <i className="fa fa-fw fa-user-plus" aria-hidden="true" />
              <span className="text">Seguir</span>
            </button>
          </section>

          <div className="p-2">
            <h4>@theKingInTheSouth</h4>
          </div>
          <div className="p-2">
            <p>
              Esto es una descripcion generica, a mi me gusta jugar con mis
              amigos imaginarios lalala
            </p>
          </div>
          <ListGroup>
            <ListGroupItem>X viajes creados</ListGroupItem>
            <ListGroupItem>X viajes favoritos</ListGroupItem>
            <ListGroupItem>X seguidores</ListGroupItem>
            <ListGroupItem>X seguidos</ListGroupItem>
          </ListGroup>
        </Card>
      </div>
    );
  }
}
