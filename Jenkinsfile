
pipeline {
  agent any

    //Parametrize your Build
    // select version of the application you want to deploy

  stages {

    stage("init") {
        steps {
        echo 'Pipeline INIT...'
    }}

    stage("build") { 
        steps {
        echo 'building the application...'
        sh 'mkdir play && cd play && cp -r /Home/Desktop/demo/ .'
        sh 'cd play && mkdir build && cd build && cmake .. && cmake --build .'
        sh ''
    }}
    stage("test") {
        steps {
          echo 'testing the application...'
          sh "play/build/tst/Factorial_test"
    }}
    stage("deploy") {
        steps {
          echo 'deploying the application...'
        }
    }
  }
}
