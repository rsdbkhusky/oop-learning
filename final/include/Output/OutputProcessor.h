//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_OUTPUTPROCESSOR_H
#define FINAL_OUTPUTPROCESSOR_H

#include <algorithm>
#include "../UI/IUI.h"
#include "../UI/UI.h"
#include "../UI/UIText.h"
#include "../UI/UIButton.h"
#include "../UI/UISudoku.h"
#include "../UI/UContainer.h"
#include "../UI/UContainerHorizontal.h"
#include "../UI/UContainerVertical.h"
#include "../Logic/LogicCell.h"
#include "../Logic/LogicSudoku.h"
using std::max;

class OutputProcessor {
public:
    static void initvcc(vector<vector<char>>& vcc, int n, int m) {
        vcc.resize(n);
        for (int i = 0; i < n; ++i) vcc[i].resize(m);
    }
    static vector<vector<char>> iui2vvc(IUI& iui) {
        vector<vector<char>> result;
        int n = 0, m = 0;
        if (dynamic_cast<UI*>(&iui) != nullptr) {
            if (dynamic_cast<UIText*>(&iui) != nullptr) {
                const string& text = dynamic_cast<UIText&>(iui).getText();
                initvcc(result, n = 1, m = int(text.size()));
                for (int i = 0; i < text.size(); ++i) result[0][i] = text[i];
            } else if (dynamic_cast<UIButton*>(&iui) != nullptr) {
                const string& text = dynamic_cast<UIButton&>(iui).getText();
                initvcc(result, n = 3, m = int(text.size()) + 4);
                for (int i = 0; i < n; ++i) result[i][0] = result[i][m - 1] = '*';
                for (int i = 0; i < m; ++i) result[0][i] = result[n - 1][i] = '*';
                for (int i = 0; i < text.size(); ++i) result[1][2 + i] = text[i];
            } else if (dynamic_cast<UISudoku*>(&iui) != nullptr) {
                const LogicSudoku& ls = dynamic_cast<UISudoku&>(iui).getLogicSudoku();
                int lencell = ls.getLenCell();
                initvcc(result, n = 1 + (lencell + 1) * lencell * lencell, m = 1 + (lencell + 1) * lencell * lencell);
                for (int i = 0; i < n; i += lencell + 1) {
                    for (int j = 0; j < m; ++j) {
                        result[i][j] = result[j][i] = '*';
                    }
                }
                for (int i = 0; i < n; i += (lencell + 1) * lencell) {
                    for (int j = 0; j < m; ++j) {
                        result[i][j] = result[j][i] = '#';
                    }
                }
                const vector<vector<LogicCell*>>& cells = ls.getCells();
                for (int i = 0, x = 1; i < lencell * lencell; ++i, x += lencell + 1) {
                    for (int j = 0, y = 1; j < lencell * lencell; ++j, y += lencell + 1) {
                        if (cells[i][j]->getStatus() == LogicCellStatus::PENDING) {
                            for (const auto& num: cells[i][j]->getCandidates()) {
                                char ch = num < 10 ? num + '0' : num - 10 + 'A';
                                result[x + (num - 1) / lencell][y + (num - 1) % lencell] = ch;
                            }
                        } else if (cells[i][j]->getStatus() == LogicCellStatus::CONFIRMED) {
                            int num = cells[i][j]->getNum();
                            char ch = num < 10 ? num + '0' : num - 10 + 'A';
                            result[x + (lencell - 1) / 2][y + (lencell - 1) / 2] = ch;
                        }
                    }
                }
            }
        } else if (dynamic_cast<UContainer*>(&iui) != nullptr) {
            if (dynamic_cast<UContainerHorizontal*>(&iui) != nullptr) {
                const vector<IUI*>& iuis = dynamic_cast<UContainerHorizontal&>(iui).getIUIs();
                vector<vector<vector<char>>> vvvc;
                m = iuis.size() - 1;
                for (auto iui: iuis) {
                    vvvc.push_back(iui2vvc(*iui));
                    n = max(n, (int)vvvc.back().size());
                    m += vvvc.back()[0].size();
                }
                initvcc(result, n, m);
                int yy = 0;
                for (auto vvc: vvvc) {
                    for (int i = 0, x = (n - (int)vvc.size()) / 2; i < vvc.size(); ++i, ++x) {
                        for (int j = 0, y = yy; j < vvc[0].size(); ++j, ++y) {
                            result[x][y] = vvc[i][j];
                        }
                    }
                    yy += vvc[0].size() + 1;
                }
            } else if (dynamic_cast<UContainerVertical*>(&iui) != nullptr) {
                const vector<IUI*>& iuis = dynamic_cast<UContainerVertical&>(iui).getIUIs();
                vector<vector<vector<char>>> vvvc;
                n = iuis.size() - 1;
                for (auto iui: iuis) {
                    vvvc.push_back(iui2vvc(*iui));
                    m = max(m, (int)vvvc.back()[0].size());
                    n += vvvc.back().size();
                }
                initvcc(result, n, m);
                int xx = 0;
                for (auto vvc: vvvc) {
                    for (int i = 0, x = xx; i < vvc.size(); ++i, ++x) {
                        for (int j = 0, y = (m - (int)vvc[0].size()) / 2; j < vvc[0].size(); ++j, ++y) {
                            result[x][y] = vvc[i][j];
                        }
                    }
                    xx += vvc.size() + 1;
                }
            }
        }
        return result;
    }
};


#endif //FINAL_OUTPUTPROCESSOR_H
