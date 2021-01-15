
var myHeaders = new Headers();
myHeaders.append('Authorization', 'Bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJkOWU0Y2IyNGQ1YWQ0YzRlYTRmYWMxNGY3MWIxNTkwNSIsImlhdCI6MTYxMDMxNzcwMCwiZXhwIjoxOTI1Njc3NzAwfQ.PDLfVcDZIwc-gwTn8aDZeAkX7HXEbrHIIPKVLDCIMQY');
myHeaders.append('Content-Type', 'application/json');

var myInit = {
  method: 'GET',
  headers: myHeaders,
  mode: 'no-cors',
  cache: 'default'
};

var myRequest = new Request('https://192.168.1.82:8123/api', myInit);

myContentType = myRequest.headers.get('Content-Type'); // returns 'image/jpeg'
/*
console.log(myContentType);


fetch(myRequest).then((a)=>{
    console.log(a);
});*/


fetch(myRequest, {
  headers: { Authorization: 'Bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJkOWU0Y2IyNGQ1YWQ0YzRlYTRmYWMxNGY3MWIxNTkwNSIsImlhdCI6MTYxMDMxNzcwMCwiZXhwIjoxOTI1Njc3NzAwfQ.PDLfVcDZIwc-gwTn8aDZeAkX7HXEbrHIIPKVLDCIMQY' }
}).then(function (response) {
  if (!response.ok) {
    return Promise.reject(response);
  }
  return response.text();
}).then(function (body ) {
  console.log(body);
});