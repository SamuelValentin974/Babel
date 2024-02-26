#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include <QtMultimedia>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <memory>

class AudioController : public QObject
{
    Q_OBJECT
public:
    explicit AudioController(QObject *parent = nullptr);
    void RecordAudio();
    void StopRecord();

    bool isRecording() const;
    void setIsRecording(bool newIsRecording);
    void SetInputAudio(QByteArray id);
    void SetInputAudio(QAudioDevice device);
    std::shared_ptr<QAudioOutput> output() const;
    void setOutput(const std::shared_ptr<QAudioOutput> &newOutput);
    void setOutput(const QAudioDevice &output);

    void SetInput();
    QUrl fileUrl() const;
    void setFileUrl(const QUrl &newFileUrl);

    QFile file() const;
    void setFile(const QFile &newFile);

    std::shared_ptr<QMediaPlayer> player() const;
    void setPlayer(const std::shared_ptr<QMediaPlayer> &newPlayer);

    QAudioBuffer SendData() const;
    void setSendData(QAudioBuffer newSendData);

    char *ReceivedData() const;
    void setReceivedData(char *newReceivedData);

    std::shared_ptr<QAudioDecoder> decoder() const;
    void setDecoder(const std::shared_ptr<QAudioDecoder> &newDecoder);

    QByteArray dataAudio() const;
    void setDataAudio(const QByteArray &newDataAudio);

    std::shared_ptr<QMediaRecorder> recorder() const;
    void setRecorder(const std::shared_ptr<QMediaRecorder> &newRecorder);

    std::shared_ptr<QSoundEffect> effect() const;
    void setEffect(const std::shared_ptr<QSoundEffect> &newEffect);

signals:
    void BufferRead();

private slots:
    void handleError(QMediaRecorder::Error error);
    void ReadDecoder();
private:
    bool _isRecording{};
    std::shared_ptr<QMediaRecorder> _recorder;
    std::shared_ptr<QMediaCaptureSession> _session;
    std::shared_ptr<QAudioInput> _input;
    std::shared_ptr<QAudioDecoder> _decoder;
    std::shared_ptr<QAudioOutput> _output;
    std::shared_ptr<QMediaPlayer> _player;
    std::shared_ptr<QSoundEffect> _effect;
    QAudioBuffer _SendData;
    QByteArray _dataAudio;
    char *_ReceivedData;
    QUrl _fileUrl;
};

void CheckFiles(QString filePath, QUrl fileUrl);

#endif // AUDIOCONTROLLER_H
