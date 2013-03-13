var http = require('http')
  , fs = require('fs')
  , jsdom = require('jsdom')
  , jquery = fs.readFileSync('./jquery.js').toString()
  , Step = require('./step')

var user = 'LLLLKKKK'
  , password = ''

var options = {
  host: 'pat.zju.edu.cn',
  path: '/users/sign_in',
  headers: {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
    'Referer': 'http://pat.zju.edu.cn/'
  }
}

Step(
  function fetch_login_page() {
    var req = http.get(options, this);
    req.on('error', function(e) {
      console.error('problem with request ' + e.message)
    })
  },

  function get_res(res) {
      var data = ''
      res.setEncoding('utf8')
      res.on('data', function(chunk){
        data += chunk;
      })
      res.on('end', this);
  },

  function parse(data) {
    jsdom.env({
      html: data,
      src: [jquery],
      done: this
    })
  },

  function get_token(window) {
    console.error('get auth_token successfully!');
    return window.$('input[name="authenticity_token"]').attr('value');
  },

  function login(auth_token) {
    var post_data = 
    'utf8='+encodeURIComponent('✓')+'&'+
    'authenticity_token='+encodeURIComponent(auth_token)+'&'+
    encodeURIComponent('user[handle]')+'='+encodeURIComponent(user)+'&'+
    encodeURIComponent('user[password]')+'='+encodeURIComponent(password)+'&'+
    encodeURIComponent('user[remember_me]')+'=0&'+
    'commit='+encodeURIComponent('登录');

    options['method'] = 'POST'
    options['headers']['Content-Type'] = 'application/x-www-form-urlencoded';
    options['headers']['Content-Length'] = post_data.length;  
    
    var req = http.request(options, this);
    req.on('error', function(e) {
      console.error('problem with request ' + e.message)
    })
    req.write(post_data)
    req.end();
  },

  function set_cookie(res) {
    res.setEncoding('utf8')
    var cookie = res.headers['set-cookie'];

    console.error('login successfully!')

    //scan each pages to get submissions
    delete options.method;
    delete options.headers['Content-Length'];
    delete options.headers['Content-Type'];
    options.headers['Referer'] = 'http://pat.zju.edu.cn/contests/pat-a-practise/submissions'
    options.headers['Cookie'] = cookie; 
  
    return [4345, 4750];
  },

  function fetch_submission(err, bound) {
    if (err) throw err;

    start = bound[0];
    end = bound[1];
    
    options['path'] = '/contests/pat-a-practise/submissions?page='+start;
    var req = http.get(options, function(res){
      res.setEncoding('utf8')
      var data='';
      res.on('data', function(chunk){
        data += chunk;
      })
      
      res.on('end', function() {
        jsdom.env({
          html: data,
          src: [jquery],
          done: function(errors, window) {
            try {
              var trs = window.$('tr');
              var i;
              for (i = 1;i < trs.length; i++) {
                var tds = window.$(trs[i]).children();
                if (tds.length != 8) continue;
                if (!(tds[7].children[0] && tds[1].children[0])) continue;

                if (tds[7].children[0].innerHTML.trim() == user &&
                  tds[1].children[0].innerHTML.trim() == '答案正确')
                {
                  console.log(tds[3].children[0].innerHTML + 
                    ' pat.zju.edu.cn' + tds[4].children[0].getAttribute('href'))
                }
              }
              console.error('page ' + start + ' finished')
              bound[0]++;
            } catch(err) {
              //console.error(data)
              console.error(window.$(trs[i]).html())
              console.error('page ' + start + ' failed: ' + err)
            }
            fetch_submission(undefined, bound)
          }
        })
      })
    })

    req.on('error', function(e) {
      console.error('problem with request ' + e.message)
      fetch_submission(undefined, bound)
    })
  }
)


/*// get auth token
var req = http.get(options, function(res){
  var data = ''
  res.setEncoding('utf8')
  res.on('data', function(chunk){
    data += chunk;
  })
  res.on('end', function(){
    jsdom.env({
      html: data,
      src: [jquery],
      done: function(errors, window) {

        console.log('get auth_token successfully!')

        var auth_token = window.$('input[name="authenticity_token"]').attr('value');
        
        // login
        var post_data = 
        'utf8='+encodeURIComponent('✓')+'&'+
        'authenticity_token='+encodeURIComponent(auth_token)+'&'+
        encodeURIComponent('user[handle]')+'='+encodeURIComponent(user)+'&'+
        encodeURIComponent('user[password]')+'='+encodeURIComponent(password)+'&'+
        encodeURIComponent('user[remember_me]')+'=0&'+
        'commit='+encodeURIComponent('登录');

        options['method'] = 'POST'
        options['headers']['Content-Type'] = 'application/x-www-form-urlencoded';
        options['headers']['Content-Length'] = post_data.length;  
        
        var login_req = http.request(options, function(res){
          res.setEncoding('utf8')
          var cookie = res.headers['set-cookie'];

          console.log('login successfully!')

          //scan each pages to get submissions
          delete options.method;
          delete options.headers['Content-Length'];
          delete options.headers['Content-Type'];
          options.headers['Referer'] = 'http://pat.zju.edu.cn/contests/pat-a-practise/submissions'
          options.headers['Cookie'] = cookie;
          
          fetch_submission(15, 4750)

          function fetch_submission(start, end){
            options['path'] = '/contests/pat-a-practise/submissions?page='+start;            
            var req = http.get(options, function(res){
              res.setEncoding('utf8')
              var data='';
              res.on('data', function(chunk){
                data += chunk;
              })
              
              res.on('end', function() {
                jsdom.env({
                  html: data,
                  src: [jquery],
                  done: function(errors, window) {
                    var trs = window.$('tr');
                    for (var i = 1;i < trs.length; i++) {
                      var tds = window.$(trs[i]).children();
                      if (tds[7].children[0].innerHTML.trim() == user &&
                        tds[1].children[0].innerHTML.trim() == '答案正确')
                      {
                        console.log(tds[3].children[0].innerHTML + 
                          ' pat.zju.edu.cn' + tds[4].children[0].getAttribute('href'))
                      }
                    }
                    console.log('page ' + start + ' finished')
                    fetch_submission(start+1, end)
                  }
                })
              })
            })

            req.on('error', function(e) {
              console.log('problem with request ' + e.message)
            })
          }
   
        })

        login_req.on('error', function(e) {
          console.log('problem with request ' + e.message)
        })

        login_req.write(post_data)
        login_req.end();
      }
    })
  })
})

req.on('error', function(e) {
  console.log('problem with request ' + e.message)
})



*/
