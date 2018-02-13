import React from 'react';
import './commentsList.css';

export default class CommentsList extends React.Component{
    render () {
        return (
            <div>
                <section className="info">
                    <div className="flex">
                        <a className="d-inline">
                            <img className="img-comentario" src="https://lh4.googleusercontent.com/-WHb2PGFg70g/AAAAAAAAAAI/AAAAAAAAAAA/4KM01AzHqeo/photo.jpg" alt="username" />
                        </a>
                        <div className="d-inline">
                            <a class="d-block p-2">
                                <strong className="user-nombre">Julian Prego</strong>
                                <span className="username"> @elLeecherPapu</span>
                            </a>
                            <span className="d-block">Comentario creado hace....</span>
                        </div>    
                    </div>
                </section>
                
                <section className="content">
                    <p>Alguno tiene el parcial hecho de Redes Neuoronales pls??</p>
                </section>
            </div>
        );
    }
}