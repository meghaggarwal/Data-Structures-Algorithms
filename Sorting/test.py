import os
from wsgiref.simple_server import make_server

def application(env, start_response):
  response_body = [
        '{key}: {value}'.format(key=key, value=value) for key, value in sorted(os.environ.items())
    ]
  response_body = '\n'.join(response_body)

  status = '200 ok'
  headers = [
    ('Content-type','text/plain'),
  ]

  start_response(status, headers)
  return ["Hello World".encode('utf-8')]


server = make_server('localhost', 8000, app=application)
server.serve_forever()