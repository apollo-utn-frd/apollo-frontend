import React from "react";
import ApolloNavbar from "../home/apollo-navbar/apollo-navbar";
import CommentsList from "./comments-list/comments-list";

export default class ViewRV extends React.Component {
  render() {
    return (
      <div>
        <ApolloNavbar />
        <div className="col-md-8">
          <img
            width="100%"
            src="https://res.cloudinary.com/apollo-core/image/upload/v1518474352/travels/a86e4b160a6d49e2a7997292dc03d368.png"
            alt="Card image cap"
          />
          <h3 className="d-inline">Mi viaje al centro de la tierra</h3>
          <i className="fa fa-fw fa-globe" aria-hidden="true" title="Pública" />
          <i className="fa fa-fw fa-lock" aria-hidden="true" title="Privada" />
          <p className="m-0">
            Por: @Nombredeusuario hace <span class="date"> · 10 min</span>
          </p>
          <p>
            Uno nunca sabe los peligros que te vas a encontrar cuando llegas a
            lo profundo del nucleo de este hermoso pero peligroso planeta al que
            llamamos tierra. Me gustarian unas pizzas al estilo Santiago.
          </p>
          <div className="actions">
            <button className="btn btn-warning m-2" title="Mandar a favoritos">
              <i className="fa fa-fw fa-star" aria-hidden="true" />
              <span class="cantidad"> X favoritos</span>
            </button>
            <button className="btn btn-info m-2" title="Comentar">
              <i className="fa fa-fw fa-comment" aria-hidden="true" />
              <span className="cantidad"> X comentarios</span>
            </button>
          </div>
          <CommentsList />
        </div>
        <div className="col-md-4" />
      </div>
    );
  }
}
