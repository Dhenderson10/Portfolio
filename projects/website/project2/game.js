//ez mode snake
//didn't have enough time to get the self detection
//used code from w3schools as a reference to get myself started

var player;
var my_canvas = document.getElementById("muh_canvas");
var food;
var c_width = 400;
var c_height = 400;
var grid = 2; //8

function startGame()
{
    player = new snake(20, 20, "black", 0, 0, 1);
    food = new food(20, 20, "green", 100, 100);
    screen.start();

}

var screen =
{
    canvas : my_canvas,
    start : function()
    {
        this.context = my_canvas.getContext("2d");
        this.interval = setInterval(updateGameArea, 30); //1000/10
        window.addEventListener('keydown', function (e)
        {
                screen.key = e.keyCode;
        })
    },
    clear : function() {
        this.context.clearRect(0, 0, c_width, c_height);
    }
}


function food(width, height, color, x, y)
{
  this.width = width;
  this.height = height;
  this.x = x;
  this.y = y;

  this.spawn_food = function() {
     this.x = Math.floor((Math.random() * c_width - 10) + 5);
     this.y = Math.floor((Math.random() * c_height - 10) + 5);
  }

  this.update_2 = function()
  {
      ctx = screen.context;
      ctx.fillStyle = color;
      ctx.fillRect(this.x, this.y, this.width, this.height);

  }

}

function snake(width, height, color, x, y)
{
    this.width = width;
    this.height = height;
    this.speedX = 3;
    this.speedY = 0;
    this.x = x;
    this.y = y;
    this.total = 0;
    this.tailx = [];
    this.taily = [];
    this.update = function()
    {
        ctx = screen.context;
        ctx.fillStyle = color;
        ctx.fillRect(this.x, this.y, this.width, this.height);
        for(var i = 0; i < this.tailx.length-1; i++)
        {
          ctx.fillRect(this.tailx[i], this.taily[i], 20, 20);
        }
    }
    this.newPos = function()
    {
        for(var i = 0; i < this.tailx.length-1; i++)
        {
          this.tailx[i] = this.tailx[i+1];
          this.taily[i] = this.taily[i+1];
        }

        this.tailx[this.total-1] = this.x;
        this.taily[this.total-1] = this.y;
        this.x += this.speedX*grid;
        this.y += this.speedY*grid;

    }

    this.border_check = function()
    {
       if((this.x < 0) || (this.x > c_width) || (this.y < 0) || (this.y > c_height))
       {
          screen.key = 0
          startGame();
       }
    }
    this.eat = function(food) {


       var myleft = this.x;
       var myright = this.x + (this.width);
       var mytop = this.y;
       var mybottom = this.y + (this.height);
       var otherleft = food.x;
       var otherright = food.x + (food.width);
       var othertop = food.y;
       var otherbottom = food.y + (food.height);
       var eaten = true;
       if ((mybottom < othertop) ||
              (mytop > otherbottom) ||
              (myright < otherleft) ||
              (myleft > otherright)) {
          eaten = false;
       }
       return eaten;
   }

   this.self_collide = function() {

     var tailleft;
     var tailright;
     var tailtop;
     var tailbottom;
     var collided = true;
     for(var i = 1; i < this.tailx.length-1; i++)
     {
       var myleft = this.x;
       var myright = this.x + (this.width);
       var mytop = this.y;
       var mybottom = this.y + (this.height);
       tailleft = this.tailx[i];
       tailright = this.tailx[i] + (this.width);
       tailtop = this.taily[i];
       tailbottom = this.taily[i] + (this.height);

       //failed self detection
       /*if ((myleft <= tailright) ||
              (myright >= tailleft) ||
              (mytop >= tailbottom) ||
              (mybottom <= tailtop)) {
                console.log("mybottom: <" + mybottom);
                console.log("myright: <" + myright);
                console.log("myleft: >" + myleft);
                console.log("mytop: >" + mytop);
                console.log("tailbottom: " + mybottom);
                console.log("tailright: " + tailright);
                console.log("tailleft: " + tailleft);
                console.log("tailtop: " + tailtop);

          collided = false;
          return collided;
     }
      return collided
*/
   }
}
}


function updateGameArea()
{

    screen.clear();
    player.newPos();
    player.update();
    player.border_check();
    food.update_2();

    if (screen.key == 37 && player.speedX != 3)
    {
      player.speedX = -3;
      player.speedY = 0;
    }
    if (screen.key == 39 && player.speedX != -3)
    {
      player.speedX = 3;
      player.speedY = 0;
    }
    if (screen.key == 38 && player.speedY != 3)
    {
      player.speedY = -3;
      player.speedX = 0;
    }
    if (screen.key == 40 && player.speedY != -3)
    {
      player.speedY = 3;
      player.speedX = 0;
    }
    if (player.eat(food))
    {
       player.total+=5;
       food.spawn_food();
    }
    if (player.self_collide())
    {
      startGame();
    }
}
