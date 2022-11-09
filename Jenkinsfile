pipeline {
  agent any

    //Parametrize your Build
    ////// select version of the application you want to ddddddddddddeployyyyy .

  stages {

    stage("init") {
        steps {
        echo 'Pipeline INIT...'
    }}
    stage('valid') {
        steps {
          echo 'send mail'
          emailext body:'test mail' ,recipientProviders: [[$class: 'DevelopersRecipientProvider'],[$class: 'RequestRecipientProvider']], subject:'Test'
    }}
    
    stage("deploy") {
        steps {
          echo 'deploying the application...'
        }
    }
  }
}
