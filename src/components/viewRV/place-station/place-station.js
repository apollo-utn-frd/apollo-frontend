import React from "react";
import "./placeStation.css";

export default class ViewRV extends React.Component {
  render() {
    return (
      <div className="border-top border-bottom p-4">
        <h6>
            <div className="row">
                <div className="col-md-2">
                    <strong className="marker-name">A</strong>
                </div>
                <div className="col-md-2 d-flex justify-content-center">
                    <strong>Tucuman</strong>
                </div>
            </div>
        </h6>
        <p className="m-0">Un lugar con gente de mierda</p>
      </div>
    );
  }
}
