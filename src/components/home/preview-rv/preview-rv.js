import React from 'react';
import { Card, CardImg, CardText, CardBody, CardLink,
  CardTitle, CardSubtitle } from 'reactstrap';

  export default class PreviewRV extends React.Component{
  render () {
    return (
        <div className="p-2">
        <Card>
            <CardText className="m-2">Compartida por @tuVieja</CardText>
            <img width="100%" src="https://res.cloudinary.com/apollo-core/image/upload/v1518474352/travels/a86e4b160a6d49e2a7997292dc03d368.png" alt="Card image cap" />
            <CardBody>
                <CardTitle className="d-inline">Mi viaje al centro de la tierra</CardTitle>
                <i class="fa fa-fw fa-globe" aria-hidden="true" title="Pública"></i>
                <i class="fa fa-fw fa-lock" aria-hidden="true" title="Privada"></i>
                <p className="m-0">Por: @Nombredeusuario hace <span class="date"> · 10 min</span></p>
            </CardBody>
            <CardBody className="py-0">
                <CardText>Uno nunca sabe los peligros que te vas a encontrar cuando llegas a lo profundo del nucleo de este hermoso pero peligroso planeta al que llamamos tierra. Me gustarian unas pizzas al estilo Santiago.</CardText>
            </CardBody>
            <CardBody>
            <div className="actions">
                <button className="btn btn-warning m-2" title="Mandar a favoritos">
                    <i className="fa fa-fw fa-star" aria-hidden="true"></i>
                    <span class="cantidad"> X favoritos</span>
                </button>
                <button className="btn btn-info m-2" title="Comentar">
                    <i className="fa fa-fw fa-comment" aria-hidden="true"></i>
                    <span className="cantidad"> X comentarios</span>
                </button>
            </div>
            </CardBody>
        </Card>
        </div>
    );
    }
};