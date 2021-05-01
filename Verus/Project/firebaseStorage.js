let current2 = new Date();
let cDate2 = current2.getFullYear() + '-' + (current2.getMonth() + 1) + '-' + current2.getDate();


firebase.initializeApp({
    apiKey: "AIzaSyAL59ccbKwdvEDBUbC5yTVKS5aLK-EMdnw",
    authDomain: "verus-2986e.firebaseapp.com",
    projectId: "verus-2986e",
    storageBucket: "verus-2986e.appspot.com",
    messagingSenderId: "281833635962",
    appId: "1:281833635962:web:54662d6d44425b4152fbc3",
    measurementId: "G-NC92VEXMVN"
  });
  
// Used this to check the image was correctly uploaded
// var loadFile = function(event) {
// 	var image = document.getElementById('output');
// 	image.src = URL.createObjectURL(event.target.files[0]);
//   holder = URL.createObjectURL(event.target.files[0]);
// };


function uploadFile(){
  var notyf = new Notyf();
  var linkShare = document.getElementById("linkToShare");
  let input2 = document.querySelector("#my_image").files[0]
  // console.log(input2.name);
  const storage = firebase.storage().ref('images/'+ cDate2+'-image.png');
  const task = storage.put(input2);
  task.on('state_change',
  function progress(snap){
      console.log(snap.bytesTransferred / snap.totalBytes * 100)
  },
  function error(err){
    console.log(err.message);
  },
  function completed(){
    storage.getDownloadURL().then(url=>{
      let body = document.querySelector('body')

    })
  }
  )
  linkShare.style.display="inline";
  linkShare.innerHTML+="<a style='font-size:14px'href='verus-2986e.web.app/display.html'> verus-2986e.web.app/display.html</a>";
  const notification = notyf.success('Uploaded successfully');

}

function displayFile(){
  var image = document.getElementById('output');
  var storageRef = firebase.storage().ref();
  var forestRef = storageRef.child('images/'+cDate2+'-image.png'); //grab most recent one
  forestRef.getDownloadURL().then(url => {
    image.src = url;
});
}