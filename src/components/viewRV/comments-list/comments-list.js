import React from "react";
import "./commentsList.css";

export default class CommentsList extends React.Component {
  render() {
    return (
      <div className="comentario border-top border-bottom">
        <section className="info">
          <div className="flex">
            <a className="d-inline">
              <img
                className="img-comentario p-2"
                src="https://lh4.googleusercontent.com/-WHb2PGFg70g/AAAAAAAAAAI/AAAAAAAAAAA/4KM01AzHqeo/photo.jpg"
                alt="username"
              />
            </a>
            <div className="d-inline p-2">
              <a className="d-block">
                <strong className="user-nombre">Julian Prego</strong>
                <span className="username"> @elLeecherPapu</span>
              </a>
              <span className="d-block">Comentario creado hace....</span>
            </div>
          </div>
        </section>

        <section className="p-2">
          <p>Alguno tiene el parcial hecho de Redes Neuoronales pls??</p>
        </section>
      </div>
    );
  }
}
