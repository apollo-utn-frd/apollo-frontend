module SignUpFormParams = {
  type state = {
    firstname: string,
    lastname: string,
    username: string,
    description: string
  };
  /* Defined the field types, used for validation and change handling */
  type fields = [ | `firstname | `lastname | `username | `description];
  /* Now teach ReForm how to get and set your fields given the types */
  /* The syntax goes (field, getter, setter) */
  let lens = [
    (`firstname, s => s.firstname, (s, firstname) => {...s, firstname}),
    (`lastname, s => s.lastname, (s, lastname) => {...s, lastname}),
    (`username, s => s.username, (s, username) => {...s, username}),
    (`description, s => s.description, (s, description) => {...s, description})
  ];
};

let lastname = (s: SignUpFormParams.state) => s.lastname;

let firstname = (s: SignUpFormParams.state) => s.firstname;

let getUsername = (s: SignUpFormParams.state) => s.username;

let getDescription = (s: SignUpFormParams.state) => s.description;

/* Validators
     Campos y validaciones:
     - nombre: [V.required, V.minLength(1), V.maxLength(20)]    OK!
     - apellido: [V.required, V.minLength(1), V.maxLength(20)]  OK!
     - username: [V.required, V.minLength(4), V.maxLength(20)]
     - descripcion: V.maxLength(150)
   */
let nameValidator = (getter, s) =>
  switch (Js.String.length(s |> getter)) {
  | 0 => Some("Este campo es requerido.")
  | n when n > 20 => Some("La longitud maxima de este campo es 20 caracteres")
  | _ => None
  };

let username = s =>
  switch (Js.String.length(s |> getUsername)) {
  | 0 => Some("Este campo es requerido.")
  | n when n < 4 =>
    Some("El nombre de usuario debe contener al menos 4 caracteres")
  | n when n > 20 =>
    Some("El nombre de usuario debe contener como maximo 20 caracteres")
  | _ => None
  };

let description = s =>
  Js.String.length(s |> getDescription) > 150 ?
    Some("La descripcion debe contener como maximo 150 caracteres.") : None;