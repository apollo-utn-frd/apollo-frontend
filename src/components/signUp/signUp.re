open Utils;

module V = Validators;

module P = V.SignUpFormParams;

module H = ReForm.Helpers;

module SignUpFormContainer = ReForm.Create(V.SignUpFormParams);

requireCSS("./signUp.css");

let defaults = (defaultValue, optional) =>
  switch optional {
  | Some(value) => value
  | None => defaultValue
  };

let custom = f => ReForm.Validation.Custom(f);

/* A pattern we are using to ease the reading of function as children */
let enhancer = (creds, mapper) =>
  ReForm.Validation.(
    <SignUpFormContainer
      onSubmit=(
        /* Enviar los datos del formulario al backend */
        (values, ~setSubmitting as _, ~setError as _) => {
          Js.log(Encode.formData(values) |> Json.stringify);
          Js.Promise.(
            values
            |> Api.Users.updateUser(creds)
            |> then_(response => Js.log(response) |> resolve)
            |> ignore
          );
        }
      )
      initialState={
        firstname: "",
        lastname: "",
        /* el username deberia ser inicializado al username de google */ username: "",
        description: ""
      }
      schema=[
        (`firstname, Custom(s => s |> V.nameValidator(V.firstname))),
        (`lastname, Custom(s => s |> V.nameValidator(V.lastname))),
        (`username, Custom(s => s |> V.username)),
        (`description, Custom(s => s |> V.description))
      ]>
      ...mapper
    </SignUpFormContainer>
  );

let component = ReasonReact.statelessComponent("SignUp");

let make = (~credentials, _children) => {
  ...component,
  render: _self =>
    enhancer(
      credentials, ({form, handleChange, handleSubmit, getErrorForField, _}) =>
      <form
        className="col-md-4 offset-md-4 p-4 border border-primary rounded"
        onSubmit=(
          event => {
            ReactEventRe.Synthetic.preventDefault(event);
            handleSubmit();
          }
        )>
        <h4 className="bg-primary text-white p-2"> ("Bienvenidos a Apollo" |> str) </h4>
        <label> <span> ("Nombre de Usuario" |> str) </span> </label>
        <input
          className ="form-control"
          value=form.values.username
          onChange=(H.handleDomFormChange(handleChange(`username)))
        />
        <p> (getErrorForField(`username) |> defaults("") |> str) </p>
        <label> <span> ("Nombre" |> str) </span> </label>
        <input
          className ="form-control"
          value=form.values.firstname
          onChange=(H.handleDomFormChange(handleChange(`firstname)))
        />
        <p> (getErrorForField(`firstname) |> defaults("") |> str) </p>
        <label> <span> ("Apellido" |> str) </span> </label>
        <input
          className ="form-control"
          value=form.values.lastname
          onChange=(H.handleDomFormChange(handleChange(`lastname)))
        />
        <p> (getErrorForField(`lastname) |> defaults("") |> str) </p>

        <label> <span> ("Descripcion" |> str) </span> </label>
        <textarea
          className ="form-control"
          value=form.values.description
          onChange=(H.handleDomFormChange(handleChange(`description)))
        />
        <p> (getErrorForField(`description) |> defaults("") |> str) </p>
        <button _type="submit" className="btn"> ("Aceptar" |> str) </button>
      </form>
    )
};
