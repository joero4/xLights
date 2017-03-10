// Create WebSocket connection.
const socket = new WebSocket('ws://localhost:2082');
// Connection opened
socket.addEventListener('open', function(event) {
  console.log("Socket Opened");
  socket.send('{"GetPlaylistStatus"}');
  wsStatus = 'connected';
});

socket.addEventListener('message', function(event) {
  var response = JSON.parse(event.data);
  if (response.status != undefined) {
    playingStatus = response;
  }
});
websocket_conn.onclose = function(e) {
  console.log('Socket Disconnected!');
};


// Listen for messages
// socket.addEventListener('message', function(event) {
//   console.log('Message from server', JSON.parse(event.data));
//   var response = JSON.parse(event.data);
//   var fun = 'test';
//   var fn = window[fun];
//   fn('hello');
// });
//
// function test(response) {
//   console.log("It worked");
//   console.log(response);
//   console.log(event.data);
// }
