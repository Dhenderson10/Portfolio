function is_user()
{
  localStorage.clear();
   var node = document.getElementById("welcome");
   var newNode = document.createElement("h1");
   var user = localStorage.getItem("user");
   if(user == null)
   {
     newNode.appendChild(document.createTextNode("Welcome"));
     node.appendChild(newNode);
   }
   else
   {
     newNode.appendChild(document.createTextNode("Welcome " + user));
     node.appendChild(newNode);
   }

}


function mailto()
{
    var node = document.getElementById("respond");
    var newNode = document.createElement("h2");
    if(node.childNodes[0] != undefined)
    {
      node.removeChild(node.childNodes[0]);
    }
    var string = "mailto:dannyhenderson36@gmail.com";
    //get inputs
    var input = document.getElementsByTagName("input");
    //save name in local storage
    var user = input[0].value;
    var check_name = /[0-9_!@#$%^&*():;.,]/.test(user);
    if(check_name == true || user == "")
    {
      newNode.appendChild(document.createTextNode("Invalid Name!"));
      node.appendChild(newNode);
      return false;
    }
    localStorage.setItem("user", user);
    //add subject
    string = string + "?subject=" + input[1].value;
    //get message and add to string
    string = string + "&body=" + document.getElementById("msg").value;
    window.location.href = string;
    newNode.appendChild(document.createTextNode("Thank you for your message " + user + "."));
    node.appendChild(newNode);
    return false;
}


function binary()
{
  var value = document.getElementsByTagName("input")[0].value;
  var check_num = /[0-9]/.test(value);
  var node = document.getElementById("test");
  var newNode = document.createElement("p");
  if(node.childNodes[0] != undefined)
  {
    node.removeChild(node.childNodes[0]);
  }
  if(value == 0)
  {
    newNode.appendChild(document.createTextNode("Binary Conversion: " + 0));
    node.appendChild(newNode);
    return;
  }
  if(check_num == true || value != "")
  {
    var bit;
    var string;
    while(value > 0)
    {
        bit = value % 2;
        value = value / 2;
        value = Math.floor(value);
        bit = Math.floor(bit);
        if(string == undefined)
        {
          string = "" + bit;
        }
        else
        {
          string = string + "" + bit;
        }
    }
    string = string.split("");
    string = string.reverse();
    string = string.join("");
    newNode.appendChild(document.createTextNode("Binary Conversion: " + string));
    node.appendChild(newNode);
 }
 else
 {
   newNode.appendChild(document.createTextNode("Enter a Number..."));
   node.appendChild(newNode);
 }
}

function hex()
{
  var value = document.getElementsByTagName("input")[0].value;
  var check_num = /[0-9]/.test(value);
  var node = document.getElementById("test");
  var newNode = document.createElement("p");
  if(node.childNodes[0] != undefined)
  {
    node.removeChild(node.childNodes[0]);
  }
  if(value == 0)
  {
    newNode.appendChild(document.createTextNode("Hexadecimal Conversion: " + 0));
    node.appendChild(newNode);
    return;
  }
  if(check_num == true || value != "")
  {
    var bit;
    var string;
    while(value > 0)
    {
        bit = value % 16;
        value = value / 16;
        value = Math.floor(value);
        bit = Math.floor(bit);
        if(bit == 10)
        {
           bit = 'A'
        }
        if(bit == 11)
        {
           bit = 'B'
        }
        if(bit == 12)
        {
           bit = 'C'
        }
        if(bit == 13)
        {
           bit = 'D'
        }
        if(bit == 14)
        {
           bit = 'E'
        }
        if(bit == 15)
        {
           bit = 'F'
        }
        if(string == undefined)
        {
          string = "" + bit;
        }
        else
        {
          string = string + "" + bit;
        }
    }
    string = string.split("");
    string = string.reverse();
    string = string.join("");
    newNode.appendChild(document.createTextNode("Hexadecimal Conversion: " + string));
    node.appendChild(newNode);
 }
 else
 {
   newNode.appendChild(document.createTextNode("Enter a Number..."));
   node.appendChild(newNode);
 }
}

function octal()
{
  var value = document.getElementsByTagName("input")[0].value;
  var check_num = /[0-9]/.test(value);
  var node = document.getElementById("test");
  var newNode = document.createElement("p");
  if(node.childNodes[0] != undefined)
  {
    node.removeChild(node.childNodes[0]);
  }
  if(value == 0)
  {
    newNode.appendChild(document.createTextNode("Octal Conversion: " + 0));
    node.appendChild(newNode);
    return;
  }
  if(check_num == true || value != "")
  {
    var bit;
    var string;
    while(value > 0)
    {
        bit = value % 8;
        value = value / 8;
        value = Math.floor(value);
        bit = Math.floor(bit);
        if(string == undefined)
        {
          string = "" + bit;
        }
        else
        {
          string = string + "" + bit;
        }
    }
    string = string.split("");
    string = string.reverse();
    string = string.join("");
    newNode.appendChild(document.createTextNode("Octal Conversion: " + string));
    node.appendChild(newNode);
 }
 else
 {
   newNode.appendChild(document.createTextNode("Enter a Number..."));
   node.appendChild(newNode);
 }
}
