
function sendMail(params){
  var tempParams = {
    from_name: document.getElementById("fromName").value,
    to_name: document.getElementById("toName").value,
    message: document.getElementById("message").value,
  };
  emailjs.send('service_jsw4osu','template_now7f2d',tempParams)
  .then(function(res){
    console.log("success", res.status);
  })
}
const canvas = document.getElementById('canvas'); 
const context = canvas.getContext('2d'); //canvas’s context is the pen  
const img = new Image();   //canvas requires a preloaded image to draw and not just a URI to the image. 
img.src = 'img/Mountain1.png';    
// console.log(canvasImage);  
console.log("HELLO")
img.onload = () => {context.drawImage(img, 0, 0);};
var maxWidth = 360;
console.log("maxWidth="+maxWidth);
var lineHeight = 30;
var x_pos = 120;
var y_pos = 160;
let current = new Date();
let cDate = current.getFullYear() + '-' + (current.getMonth() + 1) + '-' + current.getDate();

function clearCanvas(cnv) {
  var ctx = cnv.getContext('2d');     // gets reference to canvas context
  ctx.beginPath();    // clear existing drawing paths
  ctx.save();         // store the current transformation matrix

  // Use the identity matrix while clearing the canvas
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.clearRect(0, 0, cnv.width, cnv.height);
  ctx.restore();        // restore the transform
}

function  addTextCnv(ctx, text, x, y, maxWidth, lineHeight) {
  ctx.fillStyle = '#000000';
  ctx.font = '15px sans-serif';
  // splits the text in words to can wrap it on new lie if exceds maxWidth
  var words = text.split(' ');
  console.log(words);
  var nr_w = words.length;
  var addtxt = '';

  // // sets to add the text and rows
  for(var n = 0; n < nr_w; n++  ) {
    console.log("addtxt="+addtxt);
    console.log("n="+n);
    var txtLine = addtxt  + words[n]  + ' ';
    console.log("txtLine="+txtLine);
    var metrics = ctx.measureText(txtLine);
    var txtWidth = metrics.width;
    console.log("metrics="+metrics);
    console.log("txtWidth="+txtWidth);
    if (y > 480){ // doesn't work (I want to disable the input when we reach a certain pos)
      console.log("DISABLE ME");
      document.getElementById("text_cnv").disabled = true;
      return;
    }
    if (txtWidth > maxWidth && n > 0) {
      addtxt = words[n] + ' ';
      y  += lineHeight;

    }
    else{
      addtxt = txtLine;
    }
    
  }
  console.log("x= "+x+"y= "+y);
  ctx.fillText(addtxt, x, y);
}

document.getElementById('text_cnv').onkeyup = function() {
  // clearCanvas(canvas); if I clear the image is gone
  addTextCnv(context, this.value, x_pos, y_pos, maxWidth, lineHeight);
}

function downloadCanvas(){  
  // get canvas data  
  var image = canvas.toDataURL();  

  // create temporary link  
  var tmpLink = document.createElement( 'a' );  
  tmpLink.download = cDate+'-image.png'; // set the name of the download file 
  tmpLink.href = image;  
  document.body.appendChild( tmpLink );  
  tmpLink.click();  
  document.body.removeChild( tmpLink );  
}

