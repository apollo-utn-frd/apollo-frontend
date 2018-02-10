import React from "react";
import "./userDropdown.css";

export default class UserDropdown extends React.Component {
    
    render () {
        return (
            <div className="dropdown user-dropdown">
                
                <button type="button" className="show-dropdown center-y" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
                    <div className="user-picture radius">
                        <img src=""/>
                    </div>
                </button>
                
                <div className="dropdown-menu">
                    <ul className="dropdown-list" role="menu">
                    <li>
                        <a /* routerLink="/profile/{{user.username}}" */ className="link">
                        <i></i>Perfil</a>
                    </li>

                    <li>
                        <a /* routerLink="/settings" */ className="link">
                        <i></i>Configuración</a>
                    </li>

                    <li className="divider"></li>

                    <li>
                        <button /* onClick="logout()" */ className="link">
                        <i></i>Salir</button>
                    </li>
                    </ul>
                </div>

            </div>
        );
    }

}