    //Parametrize your Build
    ////// select version of the application you want to deploy .
pipeline {
    agent any
    environment {
        //This variable need be tested as string
        doError = '1'
    }
    stages {
        
        stage('init') {
        steps {
        echo 'Pipeline INIT...'
    }}
        stage('build') { 
        steps {
        echo 'building the application...'
        sh 'rm -rf play'
        sh 'mkdir play && cd play && cp -r /home/jangoo/Downloads/Jenkins/Project/Jenkins-Demo/ .'
        sh 'cd play && mkdir build && cd build && cmake ../.. && cmake --build .'
        sh ''
    }}
    stage('test') {
        steps {
            echo 'testing the application...'
            sh "play/build/tst/Factorial_test"
    }}
    stage('Error') {
        when {
            expression { doError == '1' }
            }
            steps {
                echo "Failure"
                error "failure test. It's work"
            }
            }
    stage('Success') {
        when {
            expression { doError == '0' }
            }
            steps {
                echo "ok"
                }
                }
                }
    post {
        always {
            echo 'I will always say Hello again!'
            
            emailext body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}\n More info at: ${env.BUILD_URL}",
            recipientProviders: [[$class: 'DevelopersRecipientProvider'], [$class: 'RequesterRecipientProvider']],
            subject: "Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}"
            }
            }
}
